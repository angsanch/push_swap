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

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`

## Usage

**Execution:**

### Arguments



### Examples

## Innerworkings

## Acknowledgments

* [42Madrid](https://www.42madrid.com/)

## Authors

* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
