import commands
from dateutil import parser
import matplotlib.pyplot as plt
import threading

seconds = [[] for x in range(3)]
maxi = 10**5
div = 5000
class SortThread(threading.Thread):
	"""docstring for SortThread"""
	def __init__(self, alg, i):
		threading.Thread.__init__(self)
		self.alg = alg
		self.i = i
	def run(self):
		s = commands.getstatusoutput('time ./%s %d' % (self.alg,self.i*div))[1]
		print s
		for x in s.split('\n')[1:]:
			time = x.split('\t')
			t =  parser.parse(time[1])
			if time[0] == 'sys':
				seconds[0].append(t.minute*60 + t.second + t.microsecond/1000000.0)
			elif time[0] == 'user':
				seconds[1].append(t.minute*60 + t.second + t.microsecond/1000000.0)
			elif time[0] == 'real':
				seconds[2].append(t.minute*60 + t.second + t.microsecond/1000000.0)


# def exec_alg(alg, i):
# 	s = commands.getstatusoutput('time ./%s %d' % (alg,i*div))[1]
# 	print s
# 	for x in s.split('\n')[1:]:
# 		time = x.split('\t')
# 		t =  parser.parse(time[1])
# 		if time[0] == 'sys':
# 			seconds[0].append(t.minute*60 + t.second + t.microsecond/1000000.0)
# 		elif time[0] == 'user':
# 			seconds[1].append(t.minute*60 + t.second + t.microsecond/1000000.0)
# 		elif time[0] == 'real':
# 			seconds[2].append(t.minute*60 + t.second + t.microsecond/1000000.0)

def create_plot():
	fig, ax = plt.subplots()
	ax.plot([x*div for x in xrange(0, maxi/div + 1)], seconds[0], label='sys')
	ax.plot([x*div for x in xrange(0, maxi/div + 1)], seconds[1], label='user')
	ax.plot([x*div for x in xrange(0, maxi/div + 1)], seconds[2], label='real')
	ax.axis([0, maxi , 0, max(0.5, max(seconds[2]))])

	legend = ax.legend(loc='upper center', shadow=True)
	frame = legend.get_frame()
	frame.set_facecolor('0.90')

	for label in legend.get_texts():
	    label.set_fontsize('large')

	for label in legend.get_lines():
	    label.set_linewidth(1.5)  
	plt.show()



def main():
	print '''
		Elige un algoritmo a analizar:
		[0] Bubble Sort
		[1] Optimized Bubble Sort
		[2] Insertion Sort
		[3] Selection Sort
		[4] Shell Sort
		[5] BST
	  '''
	CHOICES = ('bubbleSort',
			   'bubbleOptimizedSort', 
			   'insertionSort', 
			   'selectionSort', 
			   'shellSort', 
			   'BST')

	op = int(raw_input())
	alg = CHOICES[op] 


	threads = []
	for i in xrange(0, maxi/div + 1):
		th = SortThread(alg, i)
		th.start()
		threads.append(th)


	for t in threads:
		t.join()

	for i in range(3):
		seconds[i].sort()
	create_plot()

if __name__ == '__main__':
	main()








	




