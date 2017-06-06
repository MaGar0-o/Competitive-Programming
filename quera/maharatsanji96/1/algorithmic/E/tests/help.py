with open('importer.sh', 'w') as out:
	while True:
		str = input()
		if str == "-1":
			exit(0)
		out.write(" ".join(str.split()[1:]))
		out.write("\n")
