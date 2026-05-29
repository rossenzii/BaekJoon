# FOOD_PRODUCT 테이블에서 식품분류별로 가격이 제일 비싼 식품의 분류, 가격, 이름을 조회하는 SQL문을 작성
# 식품분류가 '과자', '국', '김치', '식용유'인 경우만 출력시켜 주시고 결과는 식품 가격을 기준으로 내림차순 

select category, price, product_name
from food_product fp
where price = (
    select max(price)
    from food_product
    where category = fp.category
)
and category in ('과자', '국', '김치', '식용유')
order by price desc;