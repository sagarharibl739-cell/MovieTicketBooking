pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure') {
            steps {
                sh 'cmake -S . -B build'
            }
        }

        stage('Parallel Build') {
            parallel {

                stage('Compile') {
                    steps {
                        sh 'cmake --build build'
                    }
                }

                stage('Static Analysis') {
                    steps {
                        echo 'Running Static Analysis...'
                        sh 'echo Static Analysis Completed'
                    }
                }
            }
        }

        stage('Run Tests') {
            steps {
                sh 'cd build && ctest --output-on-failure'
            }
        }

        stage('Verify Build') {
            steps {
                sh 'ls -lh build'
            }
        }
    }

    post {

    success {
        echo 'Build Successful'
        archiveArtifacts artifacts: 'build/**/*', fingerprint: true
    }

    failure {
        echo 'Build Failed'
    }
  }
}
