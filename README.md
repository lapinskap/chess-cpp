# Chess Homework DSW 2022



## Work process

1) Clone the repo
2) Create your dev branch based on your master branch. Example: from ilya-master branch to ilya-dev
3) Write code
4) Add it to git. Only add those files that are required to compile and run the project. That would be the .vcxproj, .cpp/.h and some graphics data later on. Don't add .exe .obj and other files which are generated during the build process.
5) Commit them. Make sure you are still on your dev branch.
6) Push your dev branch to GitLab (origin).
7) Create a merge request from your dev branch to your master branch. Add me (Ilya Neo7k) as the reviewer and the assignee.
8) Your code gets reviewed

    If there are issues the merge request gets discarded. Go to step 3.

    If it's ok I merge and close the request. Go to sleep :)

### HW1

There's a single Knight on the board.  
The user can ask for the possible moves by typing the piece position with a question mark (**a1?**). Only valid moves are displayed.  
The user can move the piece by typing positions of the start and the destination (**a1 b3**). Invalid user input makes no effect.  
