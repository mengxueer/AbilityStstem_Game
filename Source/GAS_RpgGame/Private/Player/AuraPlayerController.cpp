// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController() {
	bReplicates = true;//开启网络复制

	
}

void AAuraPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent=CastChecked<UEnhancedInputComponent>(InputComponent);//获取输入组件并转换成增强输入组件
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);//bind移动事件
}

void AAuraPlayerController::BeginPlay() {
	Super::BeginPlay();
	check(AuraContext);//检查是否是空指针
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());//获取增强输入系统
	check(Subsystem);//检查是否空指针

	Subsystem->AddMappingContext(AuraContext,0);//添加按键映射
	
	bShowMouseCursor=true;//设置显示鼠标
	DefaultMouseCursor=EMouseCursor::Default;//设置默认光标
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); //设置鼠标模式不锁定
	InputModeData.SetHideCursorDuringCapture(false);//设置扑获到鼠标不隐藏
	SetInputMode(InputModeData);//设置输入模式
}

void AAuraPlayerController::Move(const  FInputActionValue& InputActionValue)  {
	const FVector2d   InputAxisVector=InputActionValue.Get<FVector2d>();//获取输入的向量2d的值
	const FRotator   Rotation=GetControlRotation();//获取当前控制器旋转
	const FRotator YawRotation(.0f,Rotation.Yaw,.0f);//获取控制器在绕z轴的旋转即yaw
	
	const FVector ForwardDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);// 先根据欧拉角表示的旋转向量 构造旋转矩阵，再通过矩阵获取X轴的方向向量（即正前方）
	const FVector RightDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);// 先根据欧拉角表示的旋转向量 构造旋转矩阵，再通过矩阵获取Y轴的方向向量（即右前方）
	
	//UE_LOG(LogTemp, Log, TEXT("ForwardDirection: %s,RightDirection:%s"),*ForwardDirection.ToString(),*RightDirection.ToString());
	if (APawn* controllerPawn=GetPawn<APawn>()) {//获取pawn
		
		controllerPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);//获取pawn调用AddMovementInput,,根据输入InputAxisVector.Y 正负 实现向前前后
		controllerPawn->AddMovementInput(RightDirection,InputAxisVector.X);//获取pawn调用AddMovementInput,,根据输入InputAxisVector.x 正负 实现向右前左
	}
}
