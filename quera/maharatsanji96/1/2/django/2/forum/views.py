from django.core import serializers
from django.http import HttpResponse
from forum.forms import TopicForm, PostForm
from django.shortcuts import render


def create_topic(request):
    if request.POST == {}:
        return render(request, 'forum/topic_form.html')
    topic_form = TopicForm(request.POST)
    if topic_form.is_valid():
        topic = topic_form.save()
        return HttpResponse(serializers.serialize("json", [topic]))
    else:
        return HttpResponse("NotValid")


def post_to_topic(request):
    if request.POST == {}:
        return render(request, 'forum/post_form.html')
    post_form = PostForm(request.POST)
    if post_form.is_valid():
        post = post_form.save()
        return HttpResponse(serializers.serialize("json", [post]))
    else:
        return HttpResponse("NotValid")

