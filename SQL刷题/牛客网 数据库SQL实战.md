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
AND e.emp_no <> m.emp_no
```

## 12 获取所有部门中当前员工薪水最高的相关信息

```sql

```







