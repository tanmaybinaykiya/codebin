var QnAContainer = React.createClass({
    render: function(){
        return (<div id="qna-container">{this.props.data.map(card => <QnACard card={card} key={card.id}/>)}</div>);
    }
});

var QnACard = React.createClass({
    render: function(){
        return (
            <div className="qnaCard" id={this.props.card.id} >
                <span id={this.props.card.id} className="question">{this.props.card.question}</span>
                <AnswerList answers={this.props.card.answers}/>
                <div ></div>
            </div>
            );
    }
});

var AnswerList = React.createClass({
    render: function(){
        return (<div className="answer-list">{this.props.answers.map(answer => <Answer key={answer.id} id={answer.id} answer={answer.data} />)}</div>);
    }
});

var Answer = React.createClass({
    render:function(){
        return (
            <span className="answer" id={this.props.id}> {this.props.answer}</span>
        );
    }
});

var qnaData = [
    {id:1, question:"This is the first question", answers: [{id:1, data:"this is an answer"}, {id:2, data:"this is also an answer"}]},
    {id:2, question:"This is not the first question", answers: [{id:1, data:"this is an answer 2"}, {id:2, data:"this is also an answer 2"}]},
    {id:3, question:"This is a question without answers", answers: []},
    {id:4, question:"This is a long question without answers", answers: []},
    {id:5, question:"This is a long question with a lot of answers", answers: [{id:1, data:"this is an answer 2"}, {id:2, data:"this is also an answer 2"}, {id:3, data:"this is also an answer 2"}]}
];

ReactDOM.render(
  <QnAContainer data={qnaData} />,
  document.getElementById('content')
);
