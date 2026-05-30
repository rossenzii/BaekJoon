# DEVELOPERS 테이블에서 GRADE별 개발자의 정보를 조회
select 
    case
        when (d.skill_code & sum(case when sc.category='Front End' then sc.code else 0 end)) >0
            and (d.skill_code & sum(case when sc.name='Python' then sc.code else 0 end)) >0
            then 'A'
        when (d.skill_code & sum(case when sc.name='C#' then sc.code else 0 end)) >0
            then 'B'
        when (d.skill_code & sum(case when sc.category='Front End' then sc.code else 0 end))>0
            then 'C'
    end as grade, 
    d.id, d.email
from developers d 
cross join skillcodes sc
group by d.id, d.email, d.skill_code
having grade is not null
order by grade, d.id asc