pipeline {
    agent {
        label 'macos' // Или 'any', если агенты не помечены
    }
    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', // или ваше имя ветки
                url: 'https://github.com/IlyaLed/password-generator'
            }
        }
        stage('Build') {
            steps {
                sh 'clang++ -std=c++11 -o password_generator password.cpp'
            }
        }
        stage('Test') {
            steps {
                sh '''
                OUTPUT=$(./password_generator <<< "8 1 0")
                echo "$OUTPUT" | grep -i "пароль"
                '''
            }
        }
    }
}