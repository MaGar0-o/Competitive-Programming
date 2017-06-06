name = input()
ans = name.split('.')[-1]
print(ans if ans != "gz" else "tar.gz")
