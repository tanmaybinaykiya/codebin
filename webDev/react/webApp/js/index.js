//Tweetdeck Mock
var Wrapper = React.createClass({
	getInitialState: function(){
		return ({
			page: 'lala'
		});	
	},

	render: function() {
		switch(this.state.page) {
		case 'lala':
			return (
				<div id='wrapper'>
					<Header />
					<HomePage />
					<Footer />
				</div>
			);
			break;
		case 'nana':
			return (
				<div id='wrapper'>
					<Header />
					<NanaPage />
					<Footer />
				</div>
			);
			break;
		default:
			return (
				<div id='wrapper'>
					<Header />
					<HomePage />
					<Footer />
				</div>
			);
		}
	}
});

var Header = React.createClass({
	render: function(){
		return (
			<div className="header">
				<div className="justForCentering">
					<div className="headerText">
						<span><a id="homeLink" href="index.html">Vacation</a></span>
						<span>Easiest way to shop for travel </span>
					</div>
					<div id="logo"></div>
				</div>
			</div>
		);
	}
});

var Footer = React.createClass({
	render: function(){
		return (
			<div className="footer"></div>
		);
	}
});

var NanaPage = React.createClass({
	render: function(){
		return (
			<div className="nanaPage"></div>
		);
	}
});

var HomePage = React.createClass({
	render: function(){
		return (
		<div className="homePage">
			<div id="welcomeText"><span>Find all you will need on your trip, faster, with Vacation</span></div>
			<QuestionCard />
		</div>
		);
	}
});

var QuestionCard = React.createClass({

	render: function(){
		return(
			<div id="questionCard">
				<div id="questionCardTitle"><span>Tell us about your trip</span></div>
				<FormCard defaults={{
					place:'barc', 
					activity:['swim', 'sightsee']
				}} />
			</div>
		);
	}
});

var FormCard = React.createClass({
	submitHandler:function(obj){
		console.log("submitHandler");
		console.log(obj);
	},

	handleSubmit:function(obj){
		console.log("handleSubmit");
		console.log(obj);
	},

	render: function(){
		return (
			<div className="formCard">
				<form onSubmit={this.handleSubmit}>
					<SelectForm msg="Which place are you visiting?" options={
						[{	
							name:'Barcelona',
							value:'BAR'
						},{
							name:'Leh/Ladakh',
							value:'LEH',
							isDefault: true
						},{
							name:'Goa',
							value:'GOA'
						}] 
					} />
					<RadioForm msg="What are the activities you are looking forward to?" options={
						[{
							name:'Business',
							value:'BSNS',
						}, {
							name:'Swimming/Beach',
							value:'SWIM'
						}, {
							name:'Hiking/Trek',
							value:'HIKE',
							isDefault: true
						}, {
							name:'Clubbing',
							value:'CLUB'
						}, {
							name:'Sightseeing',
							value:'SIGT'
						}] 
					} />
					<div className="subForm">
						<button id="submitButton" type="submit" value="submit"  >Lets Get Started</button>
					</div>
				</form>
			</div>
		);
	}
});

var SelectForm = React.createClass({
	
	getInitialState: function(){
		var defaultValue = null;
		var isDefault = false;
		this.props.options.map(function(opt){
			isDefault = (!!opt.isDefault) && !isDefault ; //first isDefault, will be checked
			if(isDefault){
				defaultValue=opt.value;
			}
		});
		return {
			value: defaultValue
		};
	},

	onChangeHandler: function(obj){
		console.log("onChangeHandler");
		console.log(obj);
		this.setState({
			value: obj.target.value
		});  
	},

	render: function(){
		var self = this;
		var selectOptions = this.props.options.map(function(opt){
			return(<option name="places" key={opt.value} value={opt.value} >{opt.name}</option>);
		});
		return (
			<div id="selectForm" className="subForm">
				<span id="form-question">{this.props.msg}</span>
				<select defaultValue={this.state.value} onChange={self.onChangeHandler} >
					{selectOptions}
				</select>
			</div>
		);
	}
});

var RadioForm = React.createClass({

	getInitialState: function(){
		var defaultValue = null;
		var isDefault = false;
		this.props.options.map(function(opt){
			isDefault = (!!opt.isDefault) && !isDefault ; //first isDefault, will be checked
			if(isDefault){
				defaultValue=opt.value;
			}
		});
		return {
			value: defaultValue
		};
	},

	onChangeHandler: function(obj){
		console.log("onChangeHandler");
		console.log(obj);
		this.setState({
			value: obj.target.value
		});  
	},

	render: function(){
		console.log("render");
		var self= this;
		var radioOptions=this.props.options.map(function(opt){
			return(
				<div className="input-span" key={opt.value} >
					<input type="radio" name="activities" value={opt.value} onChange={self.onChangeHandler} defaultChecked={(opt.value === self.state.value)} />
					<span>{opt.name}</span>
				</div>
			);
		});
		return (
			<div id="radio-form" className="subForm">
				<span id="form-question">{this.props.msg}</span>
				{radioOptions}
			</div>
		);
	}
});


ReactDOM.render(<Wrapper />, document.getElementById('content'));