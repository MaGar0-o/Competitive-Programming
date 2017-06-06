from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from contests.models import Contest


def add_contest(request):
    contest_title = request.GET['title']
    new_contest = Contest()
    new_contest.title = contest_title
    new_contest.save()
    return HttpResponse("OK")


def all_contests(request):
    contests = Contest.objects.all()
    result = ""
    for contest in contests:
        result += contest.title + "<br>"
    return HttpResponse(result)
