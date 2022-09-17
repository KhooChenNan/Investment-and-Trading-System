#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/* Option 5 */
float average_buy_price_calculator(float total_money_invested, int total_unit_purchased){
    float final_answer;

    final_answer = total_money_invested/(float)total_unit_purchased;

    return final_answer;
}

/* Option 6 */
float lot_size_calculator(float total_amount_risk, float amount_risk_per_trade){
    float lot_size;

    lot_size = (total_amount_risk/amount_risk_per_trade)/100000;

    return lot_size;
}

float convert_to_usd(float amount_risk_per_trade, float current_price_per_usd){ // Used to convert amount risk per trade if it isn't in USD
    float converted_price_in_usd;

    converted_price_in_usd = amount_risk_per_trade/current_price_per_usd;

    return converted_price_in_usd;
}

/* Option 7 */
float leverage_calculator(float entry_price, float stop_loss){
    float leverage, percentage_price_deviation;

    percentage_price_deviation = ((entry_price - stop_loss)/entry_price)*100;

    if(percentage_price_deviation < 0){
        percentage_price_deviation = percentage_price_deviation * -1;
    }

    leverage = 100/percentage_price_deviation;

    return leverage;
}

/* Option 8 */
float position_size_calculator(float position_size_EP, float position_size_SL, float max_admissible_risk_amount){
    float position_size;

    position_size = max_admissible_risk_amount/(position_size_EP - position_size_SL);

return position_size;
}

int main(){
    int user_input_option, total_unit_purchased, select_again_output;
    char quote_pair[3];
    float total_money_invested, average_buy_price, lot_size, total_amount_risk, risk_per_trade;
    float current_price_per_usd, price_in_usd;
    char select_again_input[10];
    FILE *fpointer;
    FILE *temp_fp;

    /* Option 2 */
    int investment_list_user_response, number_of_new_investments;
    float amount_bought;

    /* Option 7 */
    float leverage;
    float leverage_EP, leverage_SL;

    /* Option 8 */
    int position_size_leverage;
    float position_size_EP, position_size_SL;
    float max_admissible_risk_amount, position_size;

    option:
    printf("Please select from the following options:\n\n");
    printf("1. Display the list of all investments.\n");
    printf("2. Edit investment list.\n");
    printf("3. Delete an existing investment.\n");
    printf("4. Average Price calculator.\n");
    printf("5. Lot size calculator.\n");
    printf("6. Max leverage calculator.\n");
    printf("7. Crypto position size calculator.\n");
    printf("8. Terminate program.\n");
    printf("\nSelecting option: ");
    scanf("%d", &user_input_option);

    switch (user_input_option){
        case 1: // Display list of all investments.
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            FILE *fpointer = fopen("investments.txt", "r");
            char line[1000];
            while(fgets(line, sizeof(line), fpointer) != NULL){
                printf("\n%s", line);
            }

            fclose(fpointer);
            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 2: // Edit investment list.
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("1. Start a new investment list.\n");
            printf("2. Add new investments.\n");
            printf("\nOption: ");
            scanf("%d", &investment_list_user_response);
            printf("Number of new investments: ");
            scanf("%d", &number_of_new_investments);
            if (investment_list_user_response == 1) { // Rewrite a new list of investments
                FILE *fpointer = fopen("investments.txt", "w"); // Declaration and open file for writing

                fprintf(fpointer, "Name\tAverage Buy Price\tAmount Bought\tValue\n");
                for (int i = 0; i < number_of_new_investments; i++) {
                    char investment_name[13] = {0}; // Resets the string to empty
                    float investment_value = 0; // Resets the float value to empty

                    printf("\n-------------- INVESTMENT NUMBER %d --------------\n", i + 1);
                    printf("Name of Investment: ");
                    scanf("%s", &investment_name);
                    printf("Average buy price: ");
                    scanf("%f", &average_buy_price);
                    printf("Amount bought: ");
                    scanf("%f", &amount_bought);
                    printf("Value of Investment: ");
                    scanf("%f", &investment_value);
                    if (average_buy_price < 9999) { // For small cap coins that have valuation lesser than 10k
                            fprintf(fpointer, "%s\t%.2f\t\t\t%.4f\t\t%.2f\n", investment_name, average_buy_price, amount_bought, investment_value);
                    }
                    else if (average_buy_price > 9999) { // For big cap coins like Bitcoin
                            fprintf(fpointer, "%s\t%.2f\t\t%.4f\t\t%.2f\n", investment_name, average_buy_price, amount_bought, investment_value);
                    }
                }
                fclose(fpointer);
            }
            else if (investment_list_user_response == 2) { // Appends the next investment at the end
                    FILE *fpointer = fopen("investments.txt", "r"); // Calculate the number of investments
                    int number_of_lines = 0;
                    char c;
                    for (c = getc(fpointer); c != EOF; c = getc(fpointer)) { // Keeps getting character from the fpointer until it reaches EOF.
                        if (c == '\n') {
                            number_of_lines += 1;
                        }
                    }
                    fclose(fpointer);

                    FILE *fpointer2 = fopen("investments.txt", "a"); // For appending only (Add at the end of the file)
                    for (int i = 0; i < number_of_new_investments; i++) {
                        char investment_name[13] = {0};
                        float investment_value = 0;

                        printf("\n-------------- INVESTMENT NUMBER %d --------------\n", i + 1);
                        printf("Name of Investment: ");
                        scanf("%s", &investment_name);
                        printf("Average buy price: ");
                        scanf("%f", &average_buy_price);
                        printf("Amount bought: ");
                        scanf("%f", &amount_bought);
                        printf("Value of Investment: ");
                        scanf("%f", &investment_value);
                        if (average_buy_price < 9999) {
                            fprintf(fpointer2, "%s\t%.2f\t\t\t%.4f\t\t%.2f\n", investment_name, average_buy_price, amount_bought, investment_value);
                        }
                        else if (average_buy_price > 9999) {
                            fprintf(fpointer2, "%s\t%.2f\t\t%.4f\t\t%.2f\n", investment_name, average_buy_price, amount_bought, investment_value);
                        }
                    }
                fclose(fpointer2);
            }
            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 3: // Delete an existing investment.
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            int delete_investment_number;
            char filename[1024], new_filename[1024];

            printf("Investment number to be deleted: ");
            scanf("%d", &delete_investment_number);

            strcpy(new_filename, "new_");
            strcat(new_filename, "investments.txt");

            fpointer = fopen("investments.txt", "r");
            temp_fp = fopen(new_filename, "w");
            int continue_reading = 0; // true to keep reading at first
            int current_line = 1;

            do {
                char buffer[2048] = {};

                if (feof(fpointer) != 0) { // Already reached end of file
                    continue_reading = 1;
                }
                fgets(buffer, 2048, fpointer);
                if (current_line != delete_investment_number + 1) { // Prints if it's not the targeted string to be deleted
                    fputs(buffer, temp_fp);
                }
                current_line++;
            } while (continue_reading == 0);

            fclose(fpointer);
            fclose(temp_fp);

            remove("investments.txt");
            rename(new_filename, "investments.txt");

            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 4: // Average buy price calculator
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("Total money invested: ");
            scanf("%f", &total_money_invested);
            printf("Total unit purchased: ");
            scanf("%d", &total_unit_purchased);

            average_buy_price = average_buy_price_calculator(total_money_invested, total_unit_purchased);
            printf("Average buy price: %.2f\n", average_buy_price);
            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 5: // Lot size calculator
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("Is the quote pair in USD?\n");
            printf("Yes/No: ");
            scanf("%s", &quote_pair); // OR fgets(quote_pair, 3, stdin)

            if (strcmp(quote_pair, "Yes") == 0) {
                printf("Total amount risk: ");
                scanf("%f", &total_amount_risk);
                printf("Amount risk per trade: ");
                scanf("%f", &risk_per_trade);
                lot_size = lot_size_calculator(total_amount_risk, risk_per_trade);
            }
            else {
                printf("Total amount risk: ");
                scanf("%f", &total_amount_risk);
                printf("Amount risk per trade (not in USD): ");
                scanf("%f", &risk_per_trade);
                printf("Current price per USD: ");
                scanf("%f", &current_price_per_usd);
                price_in_usd = convert_to_usd(risk_per_trade, current_price_per_usd);
                lot_size = lot_size_calculator(total_amount_risk, price_in_usd);
            }

            printf("Lot size: %.3f\n", lot_size);

            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 6: // Leverage calculator
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("Entry price: ");
            scanf("%f", &leverage_EP);
            printf("Stop Loss: ");
            scanf("%f", &leverage_SL);
            leverage = leverage_calculator(leverage_EP, leverage_SL);

            printf("Max leverage (not accounting fees): %.3f\n", leverage);

            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 7: // Crypto position size calculator
            system("cls");
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("Entry price, Stop Loss, Leverage: ");
            scanf("%f, %f, %d", &position_size_EP, &position_size_SL, &position_size_leverage);
            printf("Maximum admissible risk amount: ");
            scanf("%f", &max_admissible_risk_amount);

            if (leverage_calculator(position_size_EP, position_size_SL) < position_size_leverage) {
                printf("Leverage exceeded the maximum possible value.\n");
            }
            else {
                position_size = position_size_calculator(position_size_EP, position_size_SL, max_admissible_risk_amount);
                if (position_size < 0) {
                    position_size = position_size * (-1);
                    printf("Max position size: %.3f\n", position_size);
                }
                else {
                    printf("Max position size: %.3f\n", position_size);
                }
            }

            printf("\n================= PROCESS DONE =================\n");
            printf("\nSelect again?");
            printf("\nYes/No: ");
            scanf("%s", &select_again_input);
            if (strcmp(select_again_input, "Yes") == 0) {
                system("cls");
                goto option;
            }
            else {
                goto terminate;
            }
            break;
        case 8: // Terminate program
            terminate:
            system("cls");
            printf("=================================================\n");
            printf("    Thank you for using, terminating program.\n");
            printf("==================== ABORTED ====================\n");
            break;
        default: // Invalid input
            system("cls");
            printf("=====================INVALID=====================\n");
            printf("Invalid input, please choose again.\n");

            goto option;
            break;
    }

    return 0;
}

