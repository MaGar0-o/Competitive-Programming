from django.db import models
from contests.models import Contest

# Create your models here.
class Tutorial(models.Model):

	title = models.CharField(max_length=1000, unique=True, blank=False, null=False)
	contest = models.ForeignKey(Contest, null=False, blank=False)
