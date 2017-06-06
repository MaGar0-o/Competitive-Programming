from django.shortcuts import render
from django.http import HttpResponse
from contests.models import Contest
from tutorials.models import Tutorial


# Create your views here.
def add_tutor(request):
	contest = Contest.objects.get(id=int(request.GET['contest']))
	tutorial = Tutorial.objects.filter(title=request.GET['title'])
	if len(tutorial) == 0:
		tutorial = Tutorial(title=request.GET['title'], contest=contest)
		tutorial.save()
	else:
		tutorial = tutorial[0]
	return HttpResponse(tutorial.id)


def get_tutor(request):
	contest = Contest.objects.get(id=int(request.GET['contest']))
	tutor_list = contest.tutorial_set.all()
	tutor_names_list = [t.title for t in tutor_list]
	tutor_names_list.sort(key=str.lower)
	return HttpResponse(''.join(tutor_names_list))

