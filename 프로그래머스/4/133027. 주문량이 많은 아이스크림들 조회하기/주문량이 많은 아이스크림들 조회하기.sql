select FH.FLAVOR
from FIRST_HALF FH
join JULY J on J.FLAVOR=FH.FLAVOR
group by FH.FLAVOR
order by FH.TOTAL_ORDER+sum(J.TOTAL_ORDER) desc
limit 3;