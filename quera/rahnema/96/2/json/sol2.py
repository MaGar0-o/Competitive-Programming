class User(object):

	def __init__(self, name = None, age = None, city = None, albums = None):
		self.name = name
		self.age = age
		self.city = city
		self.albums = ([] if albums is None else albums)
	
	def __str__(self):
		return "User: ({}, {}, {}) [{}]".format(self.name, self.age, self.city, ','.join(self.albums))


class Album(object):

	def __init__(self, name = None, singer = None, genre = None, tracks = None):
		self.name = name
		self.singer = singer
		self.genre = genre
		self.tracks = tracks
	

	def __str__(self):
		return "Album: ({}, {}, {}, {})".format(self.name, self.singer, self.genre, self.tracks)


n = 0
m = 0
q = 0
buffer = ""
used_buffer = True
users = []
albums = []

def get_input():
	global buffer, used_buffer
	if not used_buffer:
		return buffer
	buffer = input()
	used_buffer = False
	return get_input()


def get_user(name):
	global users
	for user in users:
		if user.name == name:
			return user
	return User()


def get_album(name):
	global albums
	for album in albums:
		if album.name == name:
			return album
	return Album()


def input_done():
	global used_buffer
	used_buffer = True


def input_user():
	name = get_input()[8:]
	input_done()
	age = int(get_input()[7:])
	input_done()
	city = get_input()[8:]
	input_done()
	albums = []
	get_input()
	input_done()
	while len(get_input().split()) == 2:
		albums.append(get_input()[6:])
		input_done()
	return User(name, age, city, albums)


def input_album():
	name = get_input()[8:]
	input_done()
	singer = get_input()[10:]
	input_done()
	genre = get_input()[9:]
	input_done()
	tracks = int(get_input()[10:])
	input_done()
	return Album(name, singer, genre, tracks)


def handle_query():
	global users, albums
	query = get_input()
	input_done()
	query = query.split()
	ans = 0
	if query[0] == "1":
		user = get_user(query[1])
		for album_name in user.albums:
			album = get_album(album_name)
			if album.singer == query[2]:
				ans += album.tracks
	elif query[0] == "2":
		user = get_user(query[1])
		for album_name in user.albums:
			album = get_album(album_name)
			if album.genre == query[2]:
				ans += album.tracks
	elif query[0] == "3":
		for user in users:
			if user.age == int(query[1]):
				for album_name in user.albums:
					album = get_album(album_name)
					if album.singer == query[2]:
						ans += album.tracks
	elif query[0] == "4":
		for user in users:
			if user.age == int(query[1]):
				for album_name in user.albums:
					album = get_album(album_name)
					if album.genre == query[2]:
						ans += album.tracks
	elif query[0] == "5":
		for user in users:
			if user.city == query[1]:
				for album_name in user.albums:
					album = get_album(album_name)
					if album.singer == query[2]:
						ans += album.tracks
	elif query[0] == "6":
		for user in users:
			if user.city == query[1]:
				for album_name in user.albums:
					album = get_album(album_name)
					if album.genre == query[2]:
						ans += album.tracks

	print(ans)
	return


def main():
	global n, m, q, users, albums
	n = int(get_input())
	input_done()
	for i in range(n):
		users.append(input_user())
	
	m = int(get_input())
	input_done()
	for i in range(m):
		albums.append(input_album())
	
	for user in users:
		for album_name in user.albums:
			if not album_name in [album.name for album in albums]:
				print(":((((((((((((((((((((((((((")
				return -1

	q = int(get_input())
	input_done()
	for i in range(q):
		handle_query()


main()
