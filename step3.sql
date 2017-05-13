
3-1
select * from luokaijing1.peoples where school != 'GDUFS' union select * from luokaijing1.peoples where school is NULL
3-2
select exam_name,avg(grade) FROM university.exam ,university.student where student_ID = ID  group by exam_name having dept_name ='computer'
3-3
select name,avg(grade) from university.exam ,university.student where ID = student_ID and sex = 'f' group by name having avg(grade) >= 80
3-4
select budget,count(*) from university.department ,university.student where student.dept_name = department.dept_name group by student.dept_name order by count(*) asc limit 0,1;
3-5
update university.department set dept_name = 'comp.sci.' where dept_name = 'computer';
3-6
update university.department set budget = budget+2000*(select count(*) from university.student where department.dept_name = student.dept_name);
3-7
insert into university.department (dept_name,building,budget) values('avg_budget',NULL,select sum(budget)/count(budget) from  university.department )
3-8
