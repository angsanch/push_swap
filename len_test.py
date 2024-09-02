import subprocess
import matplotlib.pyplot as plt
from multiprocessing.pool import ThreadPool
import random
import sys

PUSH_SWAP = "./push_swap"
CHECKER = "./checker"

def run_test(nums:list):
	result = subprocess.run([PUSH_SWAP, *[str(i) for i in nums]], stdout=subprocess.PIPE)
	correct = subprocess.run([CHECKER, *[str(i) for i in nums]], input=result.stdout, stdout=subprocess.PIPE).stdout.decode() == "OK\n"
	amount = len([i for i in result.stdout.decode().split("\n") if len(i) > 0])
	if correct:
		return amount
	else:
		return -amount

def run_tests(amount:int, params:int):
	numbers = [list(range(params)) for _ in range(amount)]
	for i in numbers:
		random.shuffle(i)
	with ThreadPool(20) as pool:
		results = pool.map(run_test, numbers)
		pool.close()
		pool.join()
	return results

def graph(levels:list, per_level:int):
	nbs = []
	correct = []
	ops_correct = []
	incorrect = []
	ops_incorrect = []
	total_points = (len(levels) * per_level)
	for i in levels:
		nbs = run_tests(per_level, i)
		correct += [j for j in nbs if j >= 0]
		incorrect += [abs(j) for j in nbs if j < 0]
		ops_correct += [i for _ in range(len(correct) - len(ops_correct))]
		ops_incorrect += [i for _ in range(len(incorrect) - len(ops_incorrect))]
		print(i)
	plt.plot(ops_incorrect, incorrect, "ro", markersize=total_points / (total_points ** 1.1))
	plt.plot(ops_correct, correct, "go", markersize=total_points / (total_points ** 1.1))
	plt.ylabel("operations")
	plt.xlabel("numbers")
	plt.show()

def print_help():
	print("""USAGE
	python3 len_test.py start stop step amount

DESCRIPTION
	start	Starting position
	stop	Stop position (not included)
	step	Incrementation
	amount	Tests performed per step

OTHER
	start, stop and step are directly used in range python built in""")

def main():
	if len(sys.argv) == 2:
		if sys.argv[1] == "-h":
			print_help()
			return
	if len(sys.argv) == 5:
		graph(list(range(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))), int(sys.argv[4]))
	else:
		raise ValueError("Invalid ammount of parameters.")

if __name__ == "__main__":
	try:
		main()
	except Exception as e:
		print(e, file=sys.stderr)
		exit(84)
