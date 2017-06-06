-- Section1
	insert into auth_user (username, first_name, last_name, city, salary)
	values ("sajadw3s", "sajad", "kazemi", "esfahan", 5245);
	insert into auth_user (username, first_name, last_name, city, salary)
	values ("ahmadnpo", "ahmad", "mohebi", "tehran", 9875);
	insert into auth_user (username, first_name, last_name, city, salary)
	values ("kazemsin", "kazem", "jafari", "mashhad", 1254);
-- Section2
	update auth_user set salary=salary+100 where first_name="Myron";
-- Section3
	delete from auth_user where username like "atillman";
-- Section4
	select uid from auth_user where salary > (select max(salary) from auth_user where username like "e%");
