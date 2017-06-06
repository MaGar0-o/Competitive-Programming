from django.conf.urls import url
from . import views

urlpatterns = [
    url(r'^topic/add', views.create_topic),
    url(r'post/add', views.post_to_topic)
]