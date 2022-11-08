# Investment and Trading System v1.0
A C program that helps to track the user's list of investments through the usage of file system storage due to the simplicity as well as the small data sets.  The four main functionalities, namely: Create, Read, Update, Delete (CRUD) can also be found in the program.

In addition to that, it also contains various calculators that help to speed up the execution process of intraday trading by being able to compute significant factors that need to be taken into account such as the maximum leverage, lot size, position sizing, and etc.

## Usage
To run the project, simply click main.c and make sure a C compiler (e.g. CodeBlocks) is installed beforehand.  Once you run, options then can be chosen from the listen.

## Description of functions

<details>
<summary>1. Display the list of all investment</summary>
<p>The entire list of investments are displayed and everything is stored inside the file "investments.txt".  All contents from both sides should be matching.</p>
</details>

<details>
<summary>2. Edit investment list</summary>
<p>User will then need to make another selection from 2 of the options given.  They can either erase and rewrite a new list of investments or they can add new investments to the existing ones.</p>
</details>

<details>
<summary>3. Delete an existing investment</summary>
<p>The "investment number" is referring to its placement within the list.  E.g. To delete the fifth investment (sixth line), enter the number "5".</p>
</details>

<details>
<summary>4. Average Price calculator</summary>
<p>Returns the average price of a certain investment after taking the total amount purchased and value invested as parameters.</p>
</details>

<details>
<summary>5. Lot size calculator</summary>
<p>FOREX lot size calculator based on the percentage risked.</p>
</details>

<details>
<summary>6. Max Leverage calculator</summary>
<p>Calculates the maximum leverage a trade can be taken ***WITHOUT*** taking into account of the fees due to different exchanges charging different rates.</p>
</details>

<details>
<summary>7. Crypto position size calculator</summary>
<p>Takes in the following as parameters: maximum admissible risk, entry price, stop loss, and leverage before calculating the position size.  The term "maximum admissible risk" is referring to the flat amount of the portfolio is being risked, not the percentage.</p>
</details>

<details>
<summary>8. Terminate program</summary>
<p>Returns 0 and closes the program.  The program may also be terminated at the end of the process by typing "No".</p>
</details>


## Additional Note
The user input is **case sensitive**, meaning if a single mistake in typo error when it comes to capitalizing will cause the entire program to terminate.

## Acknowledgements
This program is entirely written by Khoo Chen Nan, a Computer Science student studying at University of Nottingham UK Jubilee Campus.  The initial release and completion of this program is 17th of September 2022.
