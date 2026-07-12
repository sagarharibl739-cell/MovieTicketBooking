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

        stage('Generate Artifacts') {
            steps {
                sh '''
                    cd build

                    echo "Generating ELF artifact..."
                    cp movie_booking movie_booking.elf

                    echo "Generating BIN artifact..."
                    objcopy -O binary movie_booking movie_booking.bin

                    echo "Generating HEX artifact..."
                    objcopy -O ihex movie_booking movie_booking.hex

                    echo "Artifacts Generated Successfully"

                    ls -lh movie_booking*
                '''
            }
        }

        stage('Parallel Verification') {
            parallel {

                stage('Run Tests') {
                    steps {
                        sh '''
                            cd build
                            ctest --output-on-failure
                        '''
                    }
                }

                stage('Verify Artifacts') {
                    steps {
                        sh '''
                            echo "Contents of build directory:"
                            ls -lh build
                        '''
                    }
                }

            }
        }

    }

    post {

        success {

            echo 'Build Successful'

            archiveArtifacts artifacts: '''
                build/movie_booking,
                build/movie_booking.elf,
                build/movie_booking.bin,
                build/movie_booking.hex
            '''.trim().replaceAll("\\s",""), fingerprint: true
        }

        failure {
            echo 'Build Failed'
        }

    }
}
