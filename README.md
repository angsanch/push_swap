# PushSwap

Sort the data on a stack with a limited set of intructions, using the lowest possible number of actions.

Project for the main 42 cursus.

### Description

1. Rules:

- You have 2 stacks (`a` and `b`).
- `a` starts with random, unique integers.
- `b` is empty.

2. Operations:

- `sa`: Swap the first 2 elements of stack `a`
- `sb`: Swap the first 2 elements of stack `b`
- `ss`: Perform `sa` and `sb` at the same time
- `pa`: Move the first element of `b` into `a`
- `pb`: Move the first element of `a` into `b`
- `ra`: Shifts all the elements of the stack `a` up by one position
- `rb`: Shifts all the elements of the stack `b` up by one position
- `rr`: Perform `ra` and `rb` at the same time
- `rra`: Shifts all the elements of the stack `a` down by one position
- `rrb`: Shifts all the elements of the stack `b` down by one position
- `rrr`: Perform `rra` and `rrb` at the same time

3. Your Task:

- Implement push_swap to show the shortest sequence of operations to sort stack a.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [Python](https://python.org)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`
* Compile the checker by typing `make bonus`
* If you want to use bulk test, install python3 and run `python3 -m pip install -r requirements.txt`

## Usage

**Execution:**

Only the numbers forming the stack are neccesary. Numbers can be provided as a different argument each or in a single block.

```
./push_swap  numbers
./push_swap "numbers"
```

Run individual test. Both commands produce the same output, the script is provided to make your life easier.

```
export ARGS="numbers"; ./push_swap $ARGS | ./checker $ARGS
./tester.sh "numbers"
```

Run bulk tests. This will draw a table showing how many instructions were used, in red if the final result was incorrect and green if correct.

```
python3 len_test.py start stop step amount
```

### Arguments

- `numbers`: All the numbers going to be sorted. All numbers must be integers and repeating elements are not allowed.
- `start`, `stop`, `step`: Used to get the size of the number array. Directly passed to python's [range](https://docs.python.org/3/library/functions.html#func-range) function.
- `amount`: Number of tests performed by each step.

### Examples

```
./push_swap  numbers
./tester.sh "numbers"
python3 len_test.py start stop step amount
```

## Innerworkings

### Proyect structure

#### Approach

After parsing the numers and checking their validity, they are assigned the index that they would have in the sorted array. That way we can forget about the numbers real value and just think about their final position.

A copy of the unsorted stack is made, then all the sorting algorithms are tried over it, to avoid wasting time on unnecesary operations, each sort is cancelled if it surpases the amount of steps of a previously succesful algorithm.

Lastly, the successful sort with the lowest ammount of instructions is printed.

#### Tools

`lists`: As there will be several sorting attempts operations for each of them need to be stored somewhere, I choose linked lists for that. The advantage of this is that you can delay printing or avoid it altogether, allowing to compare algorithms beetween them.

`operation runner`: Will apply an operation to the stacks while adding it to the instruction list. Operations are part of an enum.

`rotations`: A function that easily rotates both of the stacks using the least amount of instructions. Sortest path will be taken and simultaneous rotations are used if in interest.

### Sorting

`simple`: Hardcoded movements that manage very small stacks, up to 3 elements.

`insertion`: Moves almost all elements to stack `b`, then sorts `a` using simple. The first element of `b` is then inserted in its possition in `a`, repeats until `b` is empty. For small stacks, up to around 100 elements.

`radix`: Implementation of the [radix](https://en.wikipedia.org/wiki/Radix_sort) sorting algorithm. It is not very efficient in this context, as a consequence its solution is rarely chosen by the program.

`ksort`: Improved version of the insertion. The main difference is that it doesn't insert the first element of `b`, it chooses the one that is closest to its final position. It also prioritizes the middle values, its important to avoid ending in the middle as it requires to rotate the entire stack to one of it extremes.

### Checker

The checker reuses a lot of the code from the main program, only a bit of parsing neccesary. Checking if stacks are sorted and operation execution were already implemented, just needed to connect them to the stdin.

## Acknowledgments

* [42Madrid](https://www.42madrid.com/)

## Authors

* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
