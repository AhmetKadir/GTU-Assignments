**CSE102 – Computer Programming (Spring 2021) Homework #11** 

**Handed out**: 7:00pm May 24, 2021. **Due**: 11:55pm June 5, 2021. 

**Hand-in  Policy**:  Via  Moodle.  No  late  submissions  will  be  accepted.  A  student  with  the  number 20180000001 should hand in  20180000001.c for this homework. 

**Collaboration Policy**: No collaboration is permitted.  

**Grading**: This homework will be graded on a scale of 100.  ![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.001.png)

Write a complete program achieving all the tasks below. 

- The program takes a single argument as the name of the file to be read. A sample file is attached (Movies.txt). The program reads this file which has labeled columns separated by commas. Every row of this text file includes information about a movie. You are asked to read every row as a string and decompose the given information (separated by commas).  
- The following shows a few entries of this file in table format. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.002.png)

**Figure.1 Movie List Example** 

- The program should keep the movies in two distinct linked lists whose nodes are named as Movie\_Budget  and  Movie\_Name.  In  Movie\_Budget,  there  should  be  three  components; budget and year are kept as integers, and the name is stored as strings, in Movie\_Name there should be three fields; genre and name as string and score as double. In the Movie\_Budget list, elements are inserted and kept in descending order by year. If years are the same, it should keep elements according to their budget in descending order. If these two values are the same, you can choose an arbitrary order among them. There should be exactly the same number of elements in these lists as the number of lines in the file.  

o  Note that the file may have multiple lines for the same movie. You should check this with the movie name. If the name is already read and stored in the list, the data should be updated with the new data. 

- The  program  should  keep  the  movie  names  and  genres  (can  be  of  arbitrary  length)  in dynamically allocated strings.  
- The number of movies in the Movies.txt file is unknown.  
- Some of the movies have no value for the 'budget' column. In this case, the string ‘unknown’ is used.  

**Part 1:** The program should support 8 different operations. Therefore, there should be a menu like the one below. The program should be terminated if and only if the user enters "8" as input. If an entry is invalid or the previously requested action has been taken, the menu should appear repeatedly. If the menu appears due to an invalid entry, there should also be an error message. 

` `![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.003.png)![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.004.png)

**Part 2:** If the user enters '1', the program should return the specified number of movie records, sorted by the selected area. As stated in the first section, if the user enters a wrong value in these selection steps, you should be directed to a new one in order to enter the correct one. If the user selects a single selection, you must return a single record. If the user selects more than one selection, you must fetch all records in the specified range. For only in multiple selections, for year or budget or score, the program should take exact year or budget or score values from the user as ranges to get related records. All rankings must be made in ascending order. Don’t forget! In the first selection, you will choose according to which field it will be sorted. 

**Part 3:** 2nd operation lists the movie genres/types as strings, if the user enters "2" as input, the program should list the genres/types as strings. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.005.png)

**Part 4:** 3rd operation lists the movies based on the information received from the user. The program asks for a "year" first, after that program asks "until that year or since that year?". Finally, the program lists the names of all movies that have been aired until / since that year. Note that the program must handle an invalid year or period values. So, if the oldest movie was released in 2000 and the user wants to print the movie that was released until 2001, the program should display an error message and request new values as there were no movies before 2001. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.006.png) ![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.007.png)

**Part 5:** 4th operation lists the movies according to information received from the user. Firstly, the program asks for a 'score', after that the program asks 'less or greater than that score?'. Finally, the program lists the names of all movies whose score is less / greater than that score. Don't forget that the program should handle the invalid score or comparison values. So, if there is no movie with a score below 4.7 and the user wants to print movies with a score below 4.7, the program should display an error message and ask for new values because there are no movies scored below 4.7. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.008.png) ![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.009.png)

**Part 6:** 5th operation asks for a movie name from the user. If the input matches with a name from the list, then the program prints all information of that movie. If the input doesn’t match with any element of the list, then it should give an error message and ask for new input. If the 'budget' information of that movie was 'unknown' when the program read it, then the users should see it as 'Unknown'. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.010.png) ![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.011.png)

**Part 7:** 6th operation basically calculates and prints the average of the IMDB scores of all movies. This value is for example purposes only. The actual value of the file given to you will be different. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.012.png)

**Part 8:** 7th operation printing the frequency of every genre. I.e. print the number of movies for every genre. These values are for example purposes only. The numbers on the file given to you will be different. 

![](Aspose.Words.00eb1ba5-e7a8-480e-9b95-e2ba844f2759.013.png)

- You are not allowed to use any library other than; 
- <stdio.h> 
- <string.h> 
- <stdlib.h> 
- You can use the ‘strtod’ function from <stdlib.h> library to parse a string to double. 
- You cannot use **realloc()** for dynamic allocation operations. You can only use **malloc()** and **calloc().** 
- If there is more than one match while performing any search, select the first one. 
- You can write your own functions to make things easier. 
- Don’t forget that the program shouldn’t terminate when an operation is done. 

**General Rules:** 

1. Obey and do not break the function prototypes that are shown on each part, otherwise, you will get zero from the related part. 
1. The program must be developed on Linux-based OS and must be compiled with GCC compiler, any problem which rises due to using another OS or compiler won't be tolerated. 
1. Note that if any part of your program is not working as expected, then you can get zero from the related part, even it’s working in some way. 
1. You can ask any question about the homework by using the forum on the Teams page of the course. 
Page 5** of 5** 
