cmake_minimum_required(VERSION 3.10)
project(SimpleServerApp)

set(CMAKE_CXX_STANDARD 11)

find_package(cpprestsdk REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)


add_executable(SimpleServerApp
        main.cpp
        src/domain/entities/user/User.hpp
        src/domain/entities/item/Item.hpp
        src/domain/services/item/ItemDomainService.hpp
        src/domain/services/user/UserDomainService.hpp
        src/infrastructure/repository/user/UserRepository.hpp
        src/infrastructure/repository/user/IUserRepository.hpp
        src/infrastructure/repository/item/IItemRepository.hpp
        src/infrastructure/repository/item/ItemRepository.hpp
        src/infrastructure/rest/controllers/baseController/Controller.hpp
        src/infrastructure/rest/controllers/user/UserController.hpp
        src/infrastructure/rest/controllers/item/ItemController.hpp
        src/application/usecases/item/ItemUseCase.hpp
        src/application/usecases/user/IUserUseCase.hpp
        src/application/usecases/user/UserUseCase.hpp
        src/application/usecases/user/UserUseCase.hpp)

target_link_libraries(SimpleServerApp PRIVATE cpprestsdk::cpprest)
