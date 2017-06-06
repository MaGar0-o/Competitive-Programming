from django import forms
from .models import Topic, Post
from datetime import datetime

class TopicForm(forms.ModelForm):

	class Meta:
		model = Topic
		fields = ('title',
				'rev_order',
				)

	
	def is_valid(self):
		if not super(TopicForm, self).is_valid():
			return False

		current_topic = self.save(commit=False)
		max_rev_order = 0
		for topic in Topic.objects.all():
			if current_topic.title in topic.title:
				return False
			if topic.rev_order > max_rev_order:
				max_rev_order = topic.rev_order
		
		if current_topic.rev_order is None:
			current_topic.rev_order = max_rev_order + 1

		return True

class PostForm(forms.ModelForm):

	class Meta:
		model = Post
		fields = ('text',
				'topic',
				)
	
	
	def is_valid(self):
		if not super(PostForm, self).is_valid():
			return False
		current_post = super(PostForm, self).save(commit=False)

		tmp = "mostafa"
		if current_post.text[:7] == tmp or current_post.text[-7:] == tmp:
			return False
		for i in range(1, len(tmp)):
			if tmp[:i] == current_post.text[:i] and tmp[i:] == current_post.text[i - 7:]:
				return False
		return True
	
	def save(self):
		post = super(PostForm, self).save()
		post.created_at = datetime.now()
		post.save()
		post.topic.last_activity = post.created_at
		post.topic.save()
		return post

