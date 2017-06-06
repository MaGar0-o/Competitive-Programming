"""Challenge URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.10/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.conf.urls import url, include
    2. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import url
from django.contrib import admin
from contests import views as contest_views
from tutorials import views as tutor_views

urlpatterns = [
    url(r'^admin/', admin.site.urls),
    url(r'contests/add', contest_views.add_contest),
    url(r'contests/all', contest_views.all_contests),
	url(r'tutorials/add', tutor_views.add_tutor),
	url(r'tutorials/get', tutor_views.get_tutor),
]
