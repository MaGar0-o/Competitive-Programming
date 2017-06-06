from django.db import models


class Contest(models.Model):
    title = models.CharField(max_length=100, unique=True)

