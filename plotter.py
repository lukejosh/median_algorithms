from matplotlib import pyplot as plt
from csv import DictReader

def main():
	size = []
	brute_force_time_taken = []
	brute_force_number_operations = []
	select_time_taken = []
	select_number_operations = []

	file = open('../results.csv')
	reader = DictReader(file)

	for row in reader:
		size.append(row['input size'])
		brute_force_time_taken.append(row['brute force - time taken'])
		brute_force_number_operations.append(row['brute force - number operations'])
		select_time_taken.append(row['select - time taken'])
		select_number_operations.append(row['select - number operations'])

	plt.plot(size, brute_force_number_operations, '.', label='data')
	plt.legend(loc='upper left')
	plt.xlabel('Size of Array')
	plt.ylabel('Number of Comparisons')
	plt.title('Brute Force')
	plt.show()