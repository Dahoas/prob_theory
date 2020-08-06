import matplotlib.pyplot as plt
import tkinter

def histogram(numbers,bins):
	for i in numbers:
		try:
			numbers = list(map(float,numbers))
			plt.title("Density")
			plt.xlabel("Value")
			plt.ylabel("Frequency")
			plt.show()
			plt.close('all')
		except:
			print('Please input numbers only')

numbers = input("Enter numbers: ").split(',')
bins = numbers.length()