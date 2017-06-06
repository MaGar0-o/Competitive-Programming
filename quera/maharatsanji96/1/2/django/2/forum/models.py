from django.db import models


class Topic(models.Model):
    title = models.CharField(max_length=100)
    rev_order = models.IntegerField(blank=True, null=True)
    last_activity = models.DateTimeField(null=True, blank=True)


class Post(models.Model):
    text = models.TextField()
    topic = models.ForeignKey(Topic, null=True, blank=True)
    created_at = models.DateTimeField(null=True, blank=True)
