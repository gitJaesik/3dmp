# 3dmp
3dmp 첫번째 기본 게임 개발

20170122 변경사항

1. ActorInfo::initialize() 메소드 추가
(Actor의 공통되는 정보를 쉽게 업데이트 하기 위해서 사용)

2. 멤버 변수명을 pt에서 _pt로 변경
예전에는 m_pt와 같이 사용했었으나 근래에는 _pt방식을 선호

3. ActorManager와 Renderer 클래스를 싱글톤 방식으로 사용

사용된 싱글톤 방식 : 클래스 내 static변수로 선언하여 (클래스변수) 한번 생성자로 인하여 생성되면 계속 클래스 변수를 사용하는 방식

4. ActorManager에 AddActor와 RemoveActor 메소드를 추가
AddActor() 메소드는 vector에 해당하는 actor를 더하는 방법

RemoveActor() 메소드는 vector에 존재하는 actor들을 모두 지운 후 vector의 공간을 초기화 하는 방법

5. draw이름을 objectShape로 변경

6. view 이름을 buffer로 변경

7. update() 부분을 싱글톤의 actormanager를 불러들임으로 의존성 약화시킴
