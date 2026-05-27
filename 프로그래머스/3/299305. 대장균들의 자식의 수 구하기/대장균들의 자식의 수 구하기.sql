select E.ID,
        count(C.ID) as CHILD_COUNT
from ECOLI_DATA E
left join ECOLI_DATA C on C.PARENT_ID = E.ID
group by E.ID
order by E.ID;