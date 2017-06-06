class Queue(object):

	def __init__(self, worker_list):
		self.wcnt = len(worker_list)
		self.worker_list = worker_list
		self.worker_list.sort()
		self.busy = [False] * self.wcnt
		self.time = [0] * self.wcnt
		self.task_list = []
	
	
	def insert(self, task):
		self.task_list.append(task)


	def get_best_worker(self):
		free_index_list = [i for i,worker in enumerate(self.worker_list) if not self.busy[i]]
		free_time_list = [self.time[id] for id in free_index_list]
		mn_time = min(free_time_list)
		wid = free_index_list[free_time_list.index(mn_time)]
		worker = self.worker_list[wid]

		self.busy[wid] = True

		return worker

	
	def get_task(self):

		if self.wcnt == 0:
			return -1

		if len(self.task_list) == 0:
			return -2

		if not any([not x for x in self.busy]):
			return -3

		task = self.task_list[0]
		self.task_list.remove(task)
		
		result = {}
		result['task'] = task
		result['worker'] = self.get_best_worker()
		return result


	def task_done(self, worker, time):
		wid = self.worker_list.index(worker)
		self.busy[wid] = False
		self.time[wid] += time

