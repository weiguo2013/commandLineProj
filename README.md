# commandLineProj
Command Line Application that takes in a user input. 
First:
if the user typed "quit" , the program exit. (ps: if user typed quit but any as substring of the input as  "quitquit",it will be processed in to second part)
Second :
And the user input will be divieded into three category:
1. if it is a numberical sequence input(nartural numbers).The program will display the mean,median,mode,range.
2. if it is a literal string,count the occurance of each character(case sensitive) and display it in alphabetical oreder. Spaces and specisal characters will be ingnored. 
3. if it the input contains both number and alphabet, it show invalid input, and as the user to to enter the intput again.


Test Cases covered:
1. "1 2 13 45 99 0 0 0 1"
2. "sunsoutgunsout"
3. "I am n0thing mr3 than a string"

And the below is the corresponding output
Enter input: 
1 2 13 45 99 0 0 0 1
mean = 17
median = 1
mode = 0
Range = 99
Enter input: 
0
mean = 0
median = 0
mode = none 
Range = 0
Enter input: 
sunsoutgunsout
g : 1
n : 2
o : 2
s : 3
t : 2
u : 4
Enter input: 
quit quit
i : 2
q : 2
t : 2
u : 2
Enter input: 
I am n0thing mr3 than a string
Wrong input! Please type in either a literal string or a number seqence!
Enter input: 
Program ended with exit code: 9
