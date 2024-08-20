import subprocess
import matplotlib.pyplot as plt
from multiprocessing.pool import ThreadPool
import random
import sys

def run_test(nums:list):
	result = subprocess.run(["./push_swap", *[str(i) for i in nums]], stdout=subprocess.PIPE)
	return len(result.stdout.decode().split("\n"))

def run_tests(amount:int, params:int):
	numbers = [list(range(params)) for _ in range(amount)]
	for i in numbers:
		random.shuffle(i)
	with ThreadPool(20) as pool:
		results = pool.map(run_test, numbers)
		pool.close()
		pool.join()
	return results

def main(levels:list, per_level:int):
	ops = []
	nbs = []
	total_points = (len(levels) * per_level)
	for i in levels:
		nbs += run_tests(per_level, i)
		ops += [i for _ in range(per_level)]
		print(i)
	plt.plot(ops, nbs, "ro", markersize=total_points / (total_points ** 1.1))
	plt.ylabel("operations")
	plt.xlabel("numbers")
	plt.show()

if __name__ == "__main__":
	try:
		main(list(range(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))), int(sys.argv[4]))
	except Exception as e:
		print(e, file=sys.stderr)
		exit(84)
