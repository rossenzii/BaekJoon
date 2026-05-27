select C.CAR_ID
from CAR_RENTAL_COMPANY_CAR C
join CAR_RENTAL_COMPANY_RENTAL_HISTORY H on H.CAR_ID = C.CAR_ID
where C.CAR_TYPE='세단' and substring(H.START_DATE,6,2)=10
group by C.CAR_ID
order by CAR_ID desc;