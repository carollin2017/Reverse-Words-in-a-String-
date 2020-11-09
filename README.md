# Reverse-Words-in-a-String

Use a stack to pass in a string and reverse each word in the string.For instance, if you
have the string “When Chuck Norris falls in water, Chuck Norris doesn't get wet. Water
gets Chuck Norris.” It should now say, “nehW kcuhC sirroN sllaf ni retaw, …” That is, it
should take in one stringand be a function(or multiple functions) that use a stack(or
multiple stacks) to reverse each word in the sentence.Create a text file that you input of
Chuck Norris jokesand have the program reverse each of the jokes.
************************************************************************************************************************
Algorithm:

reverse_word() will reverse the take in string, we assume it is a word instead of a senntence.
reverse_word() will use a char stack to stock every character in the string, and then use another empty
string res to store every character that is on the top of the stack, then pop the character we have stored.
Since stack is FILO, the res string we get is the reverse of the original string.

reverse() will take two strings that represents the input and output filename we are going to read and write.
Instead of reading the file word by word, we read the file line by line. 
We split the line by space, then use the reverse_word() to reverse every word we split and write it to the
output file. 
