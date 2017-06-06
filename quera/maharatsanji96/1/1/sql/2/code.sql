-- Section1
	select company_name, ccity
	from works
	where avg(salary) > (select avg(salary) from works where company_name like "Walker Group")
	group by company_name;
-- Section2
	select company_name, ccity
	from works
	where count(employee_name)=(select max(y.num) from (select count(employee_name) as num from works group by company_name,ccity) y)
	group by company_name, ccity;
-- Section3
	select employee_name
	from works
	where salary > (select max(salary) from works where company_name="Walker Group")
	group by employee_name;
