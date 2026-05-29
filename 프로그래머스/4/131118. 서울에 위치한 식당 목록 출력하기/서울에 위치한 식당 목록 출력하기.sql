# 서울에 위치한 식당들의 식당 ID, 식당 이름, 음식 종류, 즐겨찾기수, 주소, 리뷰 평균 점수를 조회
# 리뷰 평균점수는 소수점 세 번째 자리에서 반올림 해주시고 결과는 평균점수를 기준으로 내림차순 정렬해주시고, 평균점수가 같다면 즐겨찾기수를 기준으로 내림차순 정렬
select ri.rest_id, ri.rest_name, ri.food_type, ri.favorites, ri.address, 
    round(avg(rr.review_score),2) as score
from rest_info ri
join rest_review rr on rr.rest_id=ri.rest_id
where ri.address like '서울%'
group by ri.rest_id, ri.rest_name, ri.food_type, ri.favorites, ri.address
order by score desc, ri.favorites desc;