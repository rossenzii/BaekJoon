# 2022년 3월의 오프라인/온라인 상품 판매 데이터의 판매 날짜, 상품ID, 유저ID, 판매량

select sales_date, product_id, user_id, sales_amount
from online_sale
where sales_date>='2022-03-01' and sales_date<'2022-04-01'

union all

select sales_date, product_id, null as user_id, sales_amount
from offline_sale
where sales_date>='2022-03-01' and sales_date<'2022-04-01'

order by sales_date asc, product_id asc, user_id asc;


