# 2022년 3월의 오프라인/온라인 상품 판매 데이터의 판매 날짜, 상품ID, 유저ID, 판매량
select SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
from ONLINE_SALE 
where SALES_DATE >='2022-03-01' and SALES_DATE<'2022-04-01'

union all

select SALES_DATE, PRODUCT_ID, null as USER_ID, SALES_AMOUNT
from OFFLINE_SALE
where SALES_DATE >='2022-03-01' and SALES_DATE<'2022-04-01'

order by SALES_DATE asc, PRODUCT_ID asc, USER_ID asc;