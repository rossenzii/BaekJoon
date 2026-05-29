# FOOD_PRODUCT와 FOOD_ORDER 테이블에서 생산일자가 2022년 5월인 식품들의 식품 ID, 식품 이름, 총매출을 조회하는 SQL문
#결과는 총매출을 기준으로 내림차순, 총매출이 같다면 식품 ID를 기준으로 오름차순 정렬

select fp.product_id, fp.product_name, 
    sum(fp.price*fo.amount) as total_sales
from food_product fp
join food_order fo on fo.product_id=fp.product_id
where fo.produce_date>='2022-05-01' and fo.produce_date<'2022-06-01'
group by fp.product_id
order by total_sales desc, fp.product_id asc;