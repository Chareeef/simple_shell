# Crafting the "Simple" Shell

## Inception

Our journey into the simple shell began with a vision: to create a tool that reproduce basic shell functionalities (and maybe more) . We aspired to build a shell that excels in robust process handling, proficiently troubleshoots memory leaks using Valgrind, and dynamically manages environment variables and the PATH.

## Mastering Process Handling

Our shell evolved to master process handling, utilizing the capabilities of fork, exec, and waitpid. The intricacies of managing processes were encapsulated in the code, ensuring smooth execution of commands and seamless process management.

## Valgrind: The Memory Detective

To uphold the integrity of our code, we integrated Valgrind as our memory leak detective. The process of running the shell with Valgrind became routine, addressing any reported issues to ensure a clean, leak-free codebase.

## Dynamic Environment Variables and PATH

Our shell seamlessly handled environment variables and dynamically updated the PATH. This functionality was woven into the fabric of the shell, providing users with a dynamic and intuitive experience.

## Collaborative Exploration

This project was not a solitary endeavor; it was a collaborative exploration of shell features. Contributions were not only encouraged but embraced. Both of us delved into the code, enhancing features, addressing memory leaks, and collectively elevating the overall user experience.

## Culmination

This simple shell, compiled with `gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell`, stands as the embodiment of our collective dedication to mastering shell scripting intricacies. It's not just a *simple* shell; it's an exploration into **advanced programming concepts**.