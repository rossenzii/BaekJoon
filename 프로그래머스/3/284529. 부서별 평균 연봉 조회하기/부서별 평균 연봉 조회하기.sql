select E.DEPT_ID, 
			D.DEPT_NAME_EN, 
			round(avg(E.SAL)) as AVG_SAL
from HR_EMPLOYEES E
left join HR_DEPARTMENT D on D.DEPT_ID=E.DEPT_ID
group by E.DEPT_ID, D.DEPT_NAME_EN
order by AVG_SAL desc;

