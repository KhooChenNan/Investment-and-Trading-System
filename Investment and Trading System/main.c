#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Option 5 */
float calculate_average_buy_price(float total_money_invested, int total_unit_purchased){
    float final_answer;

    final_answer = total_money_invested/(float)total_unit_purchased;

    return final_answer;
}

/* Option 6 */
float calculate_lot_size(float total_amount_risk, float amount_risk_per_trade){
    float lot_size;

    lot_size = (total_amount_risk/amount_risk_per_trade)/100000;

    return lot_size;
}

float convert_to_usd(float amount_risk_per_trade, float current_price_per_usd){ // Used to convert amount risk per trade if it isn't in USD
    float converted_price_in_usd;

    converted_price_in_usd = amount_risk_per_trade/current_price_per_usd;

    return converted_price_in_usd;
}


int main(){
    int user_input_option, total_unit_purchased;
    char quote_pair[3];
    float total_money_invested, average_buy_price, lot_size, total_amount_risk, risk_per_trade;
    float current_price_per_usd, price_in_usd;


    printf("Please select from the following options:\n\n");
    printf("1. Display the list of all investments.\n");
    printf("2. Add a new investment.\n");
    printf("3. Delete an existing investment.\n");
    printf("4. Find a specific investment.\n");
    printf("5. Average Price calculator.\n");
    printf("6. Lot size calculator.\n");
    printf("7. Terminate program.\n");
    option:
    printf("\nSelecting option: ");
    scanf("%d", &user_input_option);

    switch (user_input_option){
        case 1: // Display list of all investments.
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            break;
        case 2: // Add a new investment.
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            break;
        case 3: // Delete an existing investment.
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            break;
        case 4: // Find a specific investment.
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            break;
        case 5: // Calculate average buy price
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("Total money invested: ");
            scanf("%f", &total_money_invested);
            printf("Total unit purchased: ");
            scanf("%d", &total_unit_purchased);

            average_buy_price = calculate_average_buy_price(total_money_invested, total_unit_purchased);
            printf("Average buy price: %.2f\n", average_buy_price);
            printf("=================================================\n");
            break;
        case 6: // Calculate lot size
            printf("================ OPTION NUMBER %d ================\n", user_input_option);
            printf("Is the quote pair in USD?\n");
            printf("Yes/No: ");
            scanf("%s", &quote_pair);

            if (strcmp(quote_pair, "Yes") == 0) {
                printf("Total amount risk: ");
                scanf("%f", &total_amount_risk);
                printf("Amount risk per trade: ");
                scanf("%f", &risk_per_trade);
                lot_size = calculate_lot_size(total_amount_risk, risk_per_trade);
            }
            else {
                printf("Total amount risk: ");
                scanf("%f", &total_amount_risk);
                printf("Amount risk per trade (not in USD): ");
                scanf("%f", &risk_per_trade);
                printf("Current price per USD: ");
                scanf("%f", &current_price_per_usd);
                price_in_usd = convert_to_usd(risk_per_trade, current_price_per_usd);
                lot_size = calculate_lot_size(total_amount_risk, price_in_usd);
            }

            printf("Lot size: %f\n", lot_size);

            printf("=================================================\n");
            break;
        case 7: // Terminate program
            printf("=================================================\n");
            printf("    Thank you for using, terminating program.\n");
            printf("==================== ABORTED ====================\n");
            break;
        default: // Invalid input
            printf("=====================INVALID=====================\n");
            printf("Invalid input, please choose again.\n");
            goto option;

            break;
    }

    return 0;
}
