-- Active: 1662366682577@@127.0.0.1@3306@student

create table
    student(
        sno char(10) primary key,
        sname char(20) not null,
        ssex char(2),
        sage int,
        sdept char(20)
    );

create table
    course(
        cno char(10) primary key,
        cname char(20) not null,
        cpno char(10),
        ccredit int
    );

create table
    sc(
        sno char(10),
        cno char(10),
        grade int,
        primary key(sno, cno)
    );

insert into
    student(sno, sname, ssex, sage, sdept)
values (
        '200515001',
        '赵菁菁',
        '女',
        23,
        'cs'
    ), ('200515002', '李勇', '男', 20, 'cs'), ('200515003', '张力', '男', 25, 'cs'), ('200515004', '张衡', '男', 18, 'IS'), (
        '200515005',
        '张向东',
        '男',
        25,
        'IS'
    ), (
        '200515006',
        '张向丽',
        '女',
        20,
        'IS'
    ), ('200515007', '王芳', '女', 20, 'cs'), (
        '200515008',
        '刘民生',
        '男',
        22,
        'MA'
    ), (
        '200515009',
        '王小民',
        '女',
        21,
        'MA'
    ), ('200515010', '李晨', '女', 22, 'MA'), ('200515011', '张毅', '男', 20, 'WM'), ('200515012', '杨磊', '女', 20, 'EN'), ('200515013', '李晨', '女', 19, null);

insert into
    course(cno, cname, cpno, ccredit)
values ('1', '数据库', '5', 4), ('2', '数学', null, 2), ('3', '信息系统', '1', 1), ('4', '操作系统', '6', 3), ('5', '数据结构', '7', 4), ('6', '数据处理', null, 2), ('7', 'PASCAL语言', '6', 4), ('8', '大学英语', null, 4);

insert into
    sc(sno, cno, grade)
values ('200515001', '1', 75), ('200515002', '1', 85), ('200515002', '2', 53), ('200515003', '1', 86), ('200515004', '2', 74), ('200515005', '1', 58), ('200515006', '1', 84), ('200515004', '5', 46), ('200515005', '4', 79), ('200515006', '7', 65), ('200515008', '2', 72), ('200515009', '8', null);

select
    sname,
    student.sno,
    sc.cno,
    cname
from student, course, sc
where
    sname like '_民%'
    and student.sno = sc.sno
    and sc.cno = course.cno;

select student.sno, sname
from student, sc, course
where
    student.sno = sc.sno
    and sc.cno = course.cno
    and sc.sno in(
        select sc.sno
        from sc, course
        where (
                cname = '数据库'
                or cname = '数学'
            )
            and sc.cno = course.cno
        group by sc.sno
        having COUNT(*) = 2
    )
group by student.sno, sname
having COUNT(*) = 2;

select *
from student, sc, course
where
    student.sno = sc.sno
    and sc.cno = course.cno
    and grade is null;

select *
from student
where sage <> (
        select sage
        from student
        where sname = '李勇'
    );

select
    student.sno,
    sname,
    平均成绩 = AVG(grade)
from student, sc
where student.sno = sc.sno
group by student.sno, sname
having AVG(grade) < (
        select AVG(grade)
        from student, sc
        where
            student.sname = '张力'
            and student.sno = sc.sno
        group by
            student.sno,
            sname
    );

select
    student.sno,
    sname,
    sdept,
    已修学分 = SUM(ccredit)
from student, course, sc
where
    student.sno = sc.sno
    and sc.cno = course.cno
group by
    student.sno,
    sname,
    sdept;

select
    student.sno,
    sname,
    sdept,
    不及格课程门数 = sum(
        case
            when grade < 60 then 1
            else 0
        end
    )
from student, course, sc
where
    student.sno = sc.sno
    and sc.cno = course.cno
group by
    student.sno,
    sname,
    sdept;

select
    student.sno,
    sname,
    sdept,
    grade
from sc, student
where
    student.sno = sc.sno
    and student.sno in (
        select student.sno
        from sc, student
        where
            student.sno = sc.sno
        group by student.sno
        having
            COUNT (sc.cno) = 2
    );

select sc.cno, cname
from sc, course
where sc.cno = course.cno
group by sc.cno, cname
having COUNT(sc.sno) = 1;

select sno, sname
from student
where sno in (
        select sno
        from sc
        where cno in (
                select cno
                from course
                where cname = '操作系统'
            )
    );