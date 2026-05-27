select E3.ID
from ECOLI_DATA E1
join ECOLI_DATA E2 on E2.PARENT_ID = E1.ID
join ECOLI_DATA E3 on E3.PARENT_ID = E2.ID
where E1.PARENT_ID is null
order by E3.ID;