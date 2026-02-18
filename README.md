# CS3090-Block-Project-2-SafeCracker


What This Program Does: 

My little brother got me a puzzle for Christmas this year called the SafeCracker 40 Puzzle. This is a mathmatical puzzle based on the "The Great Burglar" puzzle. The goal of the puzzle is to align all four wheels so that every column sums up to exactly 40. There is only one solution that will unlock the wheel. 

My program is a brute force attack at figuring out this puzzle. It try out every combination of the wheel until there is one that all sums are equal to 40. The program also takes into account that some of the wheels have two layers that can cover the wheel below it. 

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/68a05b98-e9c7-4b17-92ec-0e2bc1a7a97e" />


Requirements to Run: 
  C++17 compatible compiler - I used g++
  Terminal or command line enviroment to run 

  EX: g++ safeCracker40.cpp -o safeCracker40 
      ./safeCracker40 

  The program can also be run in a IDE like Eclipse or Visual Studio code as well. 


Limitations: 
  A clear limitation of the program is that it is designed to solve a specific puzzle. I thought that using a brute force attack to break at "safe" would be much safer done on a puzzle rather than a viable pin or password cracker. 

Ethical considerations and responsible use:

The project was meant to demonstrade how brute force solving can be used to break passwords or pin numbers while also solving a puzzle I did not want to do manually. The techniques used in this project could be misused as a password guesser. 

This software is for education and lawful use only and should not be adapted to harm or unethical obtain information. 
