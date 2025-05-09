pipeline {
    agent any
    
    stages {
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
    
    post {
        always {
            archiveArtifacts artifacts: 'password_generator', fingerprint: true
        }
    }
}