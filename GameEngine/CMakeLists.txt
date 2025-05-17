add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/BackdropActor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/BackdropActor.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/BackgroundLayer.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/BackgroundLayer.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/MathUtility.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/MathUtility.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/PhysicsSystem.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/PhysicsSystem.cpp


	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Delegate.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Delegate.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/VFX/Particle.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/VFX/Particle.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/TimerManager.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/TimerManager.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/GameStage.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/GameStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/WaitStage.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/WaitStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/HUD.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/HUD.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/Widget.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/Widget.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/TextWidget.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/TextWidget.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/ValueGuage.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/ValueGuage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/ImageWidget.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/ImageWidget.cpp


	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/Button.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/Button.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
	${SFML_LIB_NAME}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.5.1
	GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-audio)

set(BOX2D_LIB_NAME Box2D)
FetchContent_Declare(
	${BOX2D_LIB_NAME}
	GIT_REPOSITORY https://github.com/erincatto/box2d
	GIT_TAG v2.4.1
	GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${BOX2D_LIB_NAME})
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC box2d)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(box2d ${LIGHT_YEARS_ENGINE_TARGET_NAME})
