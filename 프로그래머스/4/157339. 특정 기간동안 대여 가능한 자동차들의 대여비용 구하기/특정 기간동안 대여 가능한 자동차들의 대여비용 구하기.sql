select C.CAR_ID,
       C.CAR_TYPE,
       ROUND(C.DAILY_FEE * 30 * (1 - P.DISCOUNT_RATE / 100)) AS FEE
from CAR_RENTAL_COMPANY_CAR C
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
    on P.CAR_TYPE = C.CAR_TYPE
    and P.DURATION_TYPE = '30일 이상'
where C.CAR_TYPE in ('세단', 'SUV')
    and C.CAR_ID not in (
        select CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where START_DATE <= '2022-11-30'
        and END_DATE >= '2022-11-01')
having FEE >= 500000 and FEE < 2000000
order by FEE desc, C.CAR_TYPE asc, C.CAR_ID desc;