# 牛客网 数据库SQL实战

## 1 查找最晚入职员工的所有信息

```sql
SELECT * FROM employees
WHERE hire_date=
(SELECT MAX(hire_date) FROM employees);
```

##### Note

1. 注意优先级顺序,括号用来改变优先级，括号中的内容最先计算

## 2 查找入职员工时间排名倒数第三的员工所有信息

```sql
SELECT * FROM employees ORDER BY hire_date DESC LIMIT 2,1;
```

##### Note

1. LIMIT 2,1等价于LIMIT 1 OFFSET 2，即从第二个（从0开始计算）元素开始（包括这个元素自身），一页最多一个

## 3 查找当前薪水详情以及部门编号dept_no

```sql
-- 使用连接查询
SELECT s.emp_no,s.salary,s.from_date,s.to_date,d.dept_no
FROM salaries s INNER JOIN dept_manager d
ON d.emp_no = s.emp_no
AND d.to_date = '9999-01-01' AND s.to_date = '9999-01-01';
```

```sql
-- 使用连接查询
SELECT s.emp_no,s.salary,s.from_date,s.to_date,d.dept_no
FROM salaries s INNER JOIN dept_manager d
ON d.emp_no = s.emp_no
WHERE d.to_date = '9999-01-01' AND s.to_date = '9999-01-01';
```

```sql
-- 使用多表查询
SELECT s.emp_no,s.salary,s.from_date,s.to_date,d.dept_no
FROM salaries s,dept_manager d
WHERE d.emp_no = s.emp_no AND d.to_date = '9999-01-01' AND s.to_date = '9999-01-01';
```

##### Note

1. 使用联结，都是要先把表联结起来成为新表，才接着进行其他操作，所以WHERE,LIMIT要放在联结的后面

2. 这里必须要把s作为主表，且两个时间都要满足，才能通过，不知道为什么，可能是牛客网的文字游戏

## 4 查找所有已经分配部门的员工的last_name和first_name以及dept_no

```sql
SELECT e.last_name,e.first_name,d.dept_no
FROM employees e INNER JOIN dept_emp d
ON e.emp_no = d.emp_no;
```

## 5 查找所有员工的last_name和first_name以及对应部门编号dept_no

```sql
SELECT e.last_name,e.first_name,d.dept_no
FROM employees e LEFT OUTER JOIN dept_emp d
ON e.emp_no = d.emp_no;
```

##### Note

如果一个员工没有分配部门，那么dept_emp这张表里就不会有他的记录

## 6 查找所有员工入职时候的薪水情况

```sql
SELECT e.emp_no,s.salary
FROM employees e,salaries s
WHERE e.emp_no = s.emp_no AND e.hire_date=s.from_date
ORDER BY e.emp_no DESC;
```

#### Note

对于e.emp_no这一列，列名就是empo_no,如果不加别名在客户机上看到的就是empo_no，加别名则显示别名。但是在代码中的时候，为了不产生歧义，必须使用完全限定列名。即可能产生歧义的列名，在SQL代码中一律使用完全限定列名

## 7 查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t

```sql
SELECT a.* FROM
(SELECT emp_no,count(*) t FROM salaries GROUP BY emp_no) a
WHERE t>15
```

```sql
SELECT emp_no,count(*) t FROM salaries GROUP BY emp_no
HAVING t>15
```

##### Note

注意区分WHERE和HAVING：

1. https://www.cnblogs.com/ljf-Sky/p/9024683.html
2. WHERE是从FROM的表里选，HAVING 是从SELECT后的表里选

## 8 找出所有员工当前薪水salary情况

```sql
SELECT salary FROM salaries WHERE to_date='9999-01-01' GROUP BY salary ORDER BY salary DESC;
```

## 9 获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，当前表示to_date='9999-01-01'

```sql
SELECT d.dept_no,d.emp_no,s.salary
FROM dept_manager d INNER JOIN salaries s
ON d.emp_no=s.emp_no AND d.to_date = '9999-01-01' AND S.to_date = '9999-01-01';
```

##### Note

牛客网上的题，凡是涉及到date的，一般都要两个表时间同时成立才行

## 10 获取所有非manager的员工emp_no

```sql
SELECT emp_no FROM employees
WHERE emp_no NOT IN (SELECT emp_no FROM dept_manager);
```

## 11 获取所有员工当前的manager

```sql
SELECT e.emp_no,m.emp_no manager_no
FROM dept_emp e INNER JOIN dept_manager m
ON e.dept_no = m.dept_no AND e.to_date='9999-01-01' AND m.to_date = '9999-01-01'
AND e.emp_no <> m.emp_no;
```

## 12 获取所有部门中当前员工薪水最高的相关信息

```sql
SELECT d.dept_no,d.emp_no,max(s.salary) salary
FROM dept_emp d INNER JOIN salaries s
ON d.emp_no = s.emp_no AND d.to_date = '9999-01-01' AND s.to_date = '9999-01-01'
GROUP BY d.dept_no;
```

## 13 从titles表获取按照title进行分组

```sql
SELECT title,COUNT(*) t FROM titles GROUP BY title HAVING t>=2;
```

##### Note

子句顺序https://blog.csdn.net/qq_23864697/article/details/80765371

## 14 从titles表获取按照title进行分组，注意对于重复的emp_no进行忽略。

```sql
SELECT title,COUNT(DISTINCT emp_no) t FROM titles GROUP BY title HAVING t>=2;
```

## 15 查找employees表

```sql
SELECT * FROM employees 
WHERE emp_no % 2 = 1 AND last_name <> 'Mary'
ORDER BY hire_date DESC;
```

##### Note

感觉sql支持的算术运算符和python差不多啊

## 16 统计出当前各个title类型对应的员工当前薪水对应的平均工资

```sql
SELECT title,avg(salary) avg FROM titles t INNER JOIN salaries s
ON t.emp_no = s.emp_no AND t.to_date = '9999-01-01' AND s.to_date = '9999-01-01'
GROUP BY title;
```

##### Note

WHERE是从FROM后面的表中筛选（算上JOIN,ON之后的），GROUP BY 是从FROM WHERE选出的表中分组，HAVING是从SELECT...FROM...(JOIN ON)...WHERE...GROUP BY...之后得到的表中筛选，ORDER BY 是在之前所有操作后得到的表中排序，最后再LIMIT OFFSET限制输出，SELECT是在后面选好的表中找列

## 17 获取当前薪水第二多的员工的emp_no以及其对应的薪水salary

```sql
SELECT emp_no,MAX(salary) salary FROM salaries
WHERE salary<(SELECT MAX(salary) FROM salaries WHERE to_date='9999-01-01') 
AND to_date='9999-01-01';
```

下面是参考别人的更具有普适性的做法，可以应对薪水第3多的，第4多的等等

```sql
SELECT emp_no,salary FROM salaries WHERE to_date = '9999-01-01' AND salary = 
(SELECT DISTINCT salary FROM salaries WHERE to_date = '9999-01-01' ORDER BY salary DESC LIMIT 1,1);
```

## 18 获取当前薪水第二多的员工的emp_no以及其对应的薪水salary，不准使用order by

```sql
SELECT e.emp_no,MAX(s.salary) salary,e.last_name,e.first_name 
FROM employees e INNER JOIN salaries s
ON e.emp_no=s.emp_no AND s.to_date = '9999-01-01'
WHERE s.salary<(SELECT MAX(s.salary) FROM salaries s WHERE s.to_date='9999-01-01');
```

## 19  查找所有员工的last_name和first_name以及对应的dept_name

```sql
SELECT e.last_name,e.first_name,dp.dept_name 
FROM employees e LEFT OUTER JOIN dept_emp d ON e.emp_no=d.emp_no
LEFT OUTER JOIN departments dp on d.dept_no = dp.dept_no;
```

##### Note

使用两次左连接

## 20 查找员工编号emp_no为10001其自入职以来的薪水salary涨幅值growth

```sql
SELECT MAX(salary)-MIN(salary) growth FROM salaries WHERE emp_no=10001;
```

上面的做法当最后一次为降薪的时候不成立，的更严谨的做法如下：

```sql
SELECT ( 
(SELECT salary FROM salaries WHERE emp_no = 10001 ORDER BY from_date DESC LIMIT 1) -
(SELECT salary FROM salaries WHERE emp_no = 10001 ORDER BY from_date ASC LIMIT 1)
) AS growth;
```

## 21 查找所有员工自入职以来的薪水涨幅情况

```sql
SELECT start.emp_no,current.salary - start.salary growth FROM
(SELECT e.emp_no,s.salary FROM employees e INNER JOIN salaries s ON e.emp_no = s.emp_no 
AND e.hire_date = s.from_date) start INNER JOIN
(SELECT e.emp_no,s.salary FROM employees e INNER JOIN salaries s ON e.emp_no = s.emp_no 
AND s.tO_date = '9999-01-01') current
ON start.emp_no = current.emp_no ORDER BY growth;
```

## 22 统计各个部门的工资记录数

```sql
SELECT d.dept_no,d.dept_name,count(m.salary) sum FROM departments d INNER JOIN
(SELECT de.dept_no,de.emp_no,s.salary FROM dept_emp de INNER JOIN salaries s ON de.emp_no = s.emp_no) m 
ON d.dept_no = m.dept_no GROUP BY d.dept_no;
```

## 23 对所有员工的薪水按照salary进行按照1-N的排名

```sql
SELECT emp_no, salaries, DENSE_RANK() OVER(ORDER BY salary DESC) AS rank
WHERE to_date = '9999-01-01' ORDER BY salary DESC, emp_no ASC;
```

1. 窗口函数的使用：

   https://www.cnblogs.com/DataArt/p/9961676.html

   注意，窗口函数的分组是在where之后的，因为它还是在SELECT子句当中的

2. 注意，序号的窗口函数是按照排序进行排序号的

3. 但是牛客网并不支持窗口函数，所以上述代码无法通过，要使用以下语句

```sql
SELECT s1.emp_no, s1.salary, COUNT(DISTINCT s2.salary) AS rank
FROM salaries AS s1, salaries AS s2
WHERE s1.to_date = '9999-01-01'  AND s2.to_date = '9999-01-01' AND s1.salary <= s2.salary
GROUP BY s1.emp_no
ORDER BY s1.salary DESC, s1.emp_no ASC;
```

## 24 获取所有非manager员工当前的薪水情况

```sql
SELECT d.dept_no,d.emp_no,s.salary FROM dept_emp d INNER JOIN salaries s ON d.emp_no = s.emp_no
WHERE d.to_date = '9999-01-01' AND s.to_date = '9999-01-01' AND d.emp_no NOT IN 
(SELECT emp_no FROM dept_manager WHERE to_date = '9999-01-01');
```

## 25 获取员工其当前的薪水比其manager当前薪水还高的相关信息

```sql
SELECT l1.emp_no,l2.emp_no manager_no,l1.salary emp_salary,l2.salary manager_salary FROM
(SELECT d.emp_no,d.dept_no,s.salary FROM dept_emp d INNER JOIN salaries s
 ON d.emp_no  = s.emp_no AND d.to_date ='9999-01-01' AND s.to_date = '9999-01-01') l1,
(SELECT d.emp_no,d.dept_no,s.salary FROM dept_manager d INNER JOIN salaries s 
 ON d.emp_no  = s.emp_no AND d.to_date ='9999-01-01' AND s.to_date = '9999-01-01') l2
WHERE l1.dept_no = l2.dept_no AND l1.salary>l2.salary;
```

## 26 汇总各个部门当前员工的title类型的分配数目

```sql
SELECT d.dept_no,d.dept_name,t.title,COUNT(t.title) count
FROM departments d INNER JOIN dept_emp p  ON d.dept_no = p.dept_no AND p.to_date = '9999-01-01'
INNER JOIN titles t ON p.emp_no = t.emp_no AND t.to_date = '9999-01-01'
GROUP BY d.dept_no,t.title;
```

## 27 给出每个员工每年薪水涨幅超过5000的员工编号emp_no

```sql
SELECT s2.emp_no, s2.from_date, (s2.salary - s1.salary) AS salary_growth
 FROM salaries AS s1, salaries AS s2
 WHERE s1.emp_no = s2.emp_no
 AND s2.salary - s1.salary > 5000
 AND strftime('%Y',s2.to_date) - strftime('%Y',s1.to_date) = 1
 ORDER BY salary_growth DESC;
```

## 28 查找描述信息中包括robot的电影对应的分类名称以及电影数目，而且还需要该分类对应电影数量>=5

```sql
SELECT ls3.name,COUNT(ls1.film_id) num
FROM film ls1 INNER JOIN film_category ls2 ON ls1.film_id = ls2.film_id
INNER JOIN category ls3 ON ls2.category_id = ls3.category_id  AND ls2.category_id IN 
(SELECT ls5.category_id FROM film ls4 INNER JOIN film_category ls5 ON ls4.film_id = ls5.film_id
GROUP BY ls5.category_id HAVING COUNT(ls4.film_id)>=5)
WHERE ls1.description LIKE '%robot%' GROUP BY ls3.name;
```

##### Note

题目中电影数目>=5 是这类电影的所有数目，并不是包含了robot的这类电影的数目，这里很坑，属于题目表述不当

## 29 使用join查询方式找出没有分类的电影id以及名称

```sql
SELECT f.film_id,f.title FROM film f LEFT JOIN film_category fc ON f.film_id = fc.film_id 
WHERE fc.category_id IS NULL;
```

## 30 使用子查询的方式找出属于Action分类的所有电影对应的title,description

```sql
SELECT f.title,f.description FROM film f WHERE f.film_id IN
(SELECT fc.film_id FROM film_category fc INNER JOIN category c ON 
 fc.category_id = c.category_id AND c.name = 'Action');
```

## 31 获取select * from employees对应的执行计划

```sql
EXPLAIN SELECT * FROM employees;
```

##### Note

通过 explain 命令获取 select 语句的执行计划:

https://www.cnblogs.com/butterfly100/archive/2018/01/15/8287569.html

https://blog.csdn.net/jianghao_ava/article/details/83187414

## 32 将employees表的所有员工的last_name和first_name拼接起来作为Name

在本题的SQLite中：

```sql
SELECT last_name||" "||first_name Name FROM employees;
```

MySQL、SQL Server、Oracle等数据库支持CONCAT方法:

```sql
select CONCAT(CONCAT(last_name," "),first_name) as Name  from employees
或者
select CONCAT(last_name," "，first_name) as Name  from employees
```

## 33 创建一个actor表，包含如下列信息

```sql
CREATE TABLE actor(actor_id smallint(5) NOT NULL,
                  first_name varchar(45) NOT NULL,
                  last_name varchar(45) NOT NULL,
                  last_update timestamp NOT NULL DEFAULT(datetime('now','localtime')),
                  PRIMARY KEY(actor_id));
```

## 34 批量插入数据

```sql
INSERT INTO actor VALUES(1,'PENELOPE','GUINESS','2006-02-15 12:34:33'),
(2,'NICK','WAHLBERG','2006-02-15 12:34:33');
```

##### Note

虽然时间数据在数据库里是特定时间类型，但是我们在插入/过滤的时候只要使用规范格式的字符串即可，数据库会自行识别转换为时间类型

