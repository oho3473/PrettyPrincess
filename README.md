# PrettyPrincess
https://github.com/user-attachments/assets/92a9274e-2271-46aa-a96a-bd1e23c1908c

식탐이 엄청난 공주가 되어 경비병과 상인들에게 들키지 않고 음식을 먹어야하는 게임입니다.

## 프로젝트 개요

| 항목 | 내용 |
| --- | --- |
| **프로젝트명** | Selic! |
| **플랫폼** | PC |
| **개발 언어** | C++ |
| **사용 기술** | DirectX 11 |
| **담당 작업** | 게임 루프 및 프레임워크 구현<br> 자체 엔진 환경에서 컨텐츠 구현 |

## 구현 상세

### 1. [NPC의 상태 설계 및 행동 구현](./GameDemo/State.h#L47C1-L70C3)

<p align="center">
<img width="426" height="240" alt="Video Project 1 (2)" src="https://github.com/user-attachments/assets/6b2235aa-eb9c-41b4-8cdb-cb071b34e40a" />
</p>

각 상태의 실제 동작은 State를 상속한 개별 클래스에서 처리하여 분리 및 FSM은 상태의 등록, 전환, 생명주기 호출만 담당하도록 구현했습니다.<br>

<img width="995" height="287" alt="image" src="https://github.com/user-attachments/assets/e26417e9-9a4e-44fc-ab35-1521bebdba6d" />

| 항목 | 내용 |
| --- | --- |
| [State](./GameDemo/State.h#L47C1-L70C3) | 상태에 대한 기본 인터페이스, 상태의 생명주기를 정의하여 파생클래스의 고유동작 정의한다 |
| PlayerState | PlayerIdle, PlayerEat, PlayerHide, PlayerThrow , PlayeRun |
| ShopKeeperState | ShopKeeperIdle, ShopKeeperIdle, ShopKeeperDoubt |
| GuardState | GuardPatrol, GuardPatrol, GuardCalled, GuardFishing, GuardComeBack, GuardSet|
| [FSM 상태 머신](/GameDemo/FSM.cpp#L13C1-L44C2) | State의 등록, 전환 및 관리를 담당 |

### 2. 플레이어 감지

<p align="center">
<img width="426" height="240" alt="Video Project 6" src="https://github.com/user-attachments/assets/408ea649-0ba0-40ea-b7cd-57bb61d6517d" />
</p>

<br>
경비병은 플레이어를 감지하면 NPC상태가  Idle → Targeting→ Chasing으로 전환되며 행동합니다
<br>

<p align="center">
<img width="669" height="294" alt="image" src="https://github.com/user-attachments/assets/88969d9e-43ed-45f8-b15d-dc7a5bf8a213" />
</p>

시야각과 거리 조건 만족시 FSM의 상태를 전환<br>

<p align="center">
<img width="426" height="240" alt="Video Project 7" src="https://github.com/user-attachments/assets/3a1bda76-c57c-4db1-ad4d-e7154999eb43" />
</p>

플레이어 감지시 A*알고리즘을 활용하여 (플레이어-경비병) 경로를 생성하고 플레이어 추격을 구현했습니다.

